#!/usr/bin/node
// takes the movie id and return characters from the endpoint is /films/
const request = require('request');

request('https://swapi-api.hbtn.io/api/films', function (err, res, body) {
  if (err) { return console.log(err); }
  const json = JSON.parse(body);

  // of vs in: of accesses element, in gives you the index of the element
  const chars = json.results.filter(function (item) {
    return item.url.includes(process.argv[2]);
  })[0].characters;

  function req (item) {
    request(item, function (err, res, body) {
      if (err) { return console.log(err); }
      console.log(JSON.parse(body).name);
    });
  }

  function delay () {
    return new Promise(resolve => setTimeout(resolve, 20));
  }

  async function delayedLog (item) {
    await delay();
    req(item);
  }

  async function processArray (chars) {
    for (const item of chars) {
      await delayedLog(item);
    }
  }

  processArray(chars);
});
