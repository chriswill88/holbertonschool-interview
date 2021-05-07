#!/usr/bin/python3
"""this module contains a function"""
import requests


def count_words(
        subreddit, word_list,
        diction_count=None, url=None, next=None, nlen=None):
    """count_words counts the number of found words in reddit hot titles"""
    # initializing the dictionary containing the updated results
    if diction_count is None:
        uniq_word = []
        diction_count = {}
        for i in word_list:
            if i.lower() not in diction_count:
                diction_count[i.lower()] = 0
            if i.lower() not in uniq_word:
                uniq_word.append(i.lower())
        word_list = uniq_word
    if url is None:
        url = 'http://www.reddit.com/r/' + subreddit + '/hot/.json'

    req = requests.get(url, headers={'User-agent': 'MikBot 0.1'})
    if req.status_code != 200:
        return

    j = req.json()
    children = j['data']['children']
    name = None
    for i in children:
        name = i['data']['name']
        title = i['data']['title']
        for t in title.split():
            if t.lower() in word_list:
                diction_count[t.lower()] += 1

    if name and name != next:
        if '?after' not in url:
            after = '?after=' + name
            nexturl = url + after
        else:
            nexturl = url[:len(url)-nlen]
            nexturl += name
    else:
        for i in sorted(
                diction_count.items(), key=lambda x: x[1], reverse=True):
            if i[1] > 0:
                print("{}: {}".format(i[0], i[1]))
        return

    req = requests.get(nexturl, headers={'User-agent': 'MikBot 0.1'})

    if req.status_code == 200:
        diction_count = count_words(
            subreddit, word_list, diction_count, nexturl, name, len(name))
