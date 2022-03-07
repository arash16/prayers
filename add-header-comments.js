#!/usr/bin/env node

const fs = require('fs');
const path = require('path');

// https://uhunt.onlinejudge.org/api/p
const problemsData = require('./problems.json');
const problemTitles = {};
for (const pd of problemsData) {
  problemTitles[pd[1]] = pd[2];
}

const extMap = {
  py: 'Python',
  c: 'C',
  cpp: 'C++',
  go: 'Go Lang',
  rs: 'Rust',
  java: 'Java',
}

const vols = fs.readdirSync('UVA');
for (const vol of vols) {
  const files = fs.readdirSync('UVA/' + vol);
  for (const file of files) {
    if (file.endsWith('.input.js')) continue;

    const filePath = `UVA/${vol}/${file}`;
    const number = parseInt(file);
    const title = problemTitles[number];
    const ext = path.extname(file).substring(1);

    let content = fs.readFileSync(filePath, 'utf8')

    if (ext == 'py') {
      content = content.replace(/^##.*/gm, '').replace(/^\s+/, '');
    } else {
      content = content.replace(/^\s*\/\*.*?\*\/\s*/s, '');
    }

    content = (ext == 'py' ? makePyComment : makeComment)(number, title, extMap[ext]) + '\n\n' + content;
    fs.writeFileSync(filePath, content);
  }
  console.log(files.map(x => problemTitles[parseInt(x)]));
}

function makeComment(number, title, lang) {
  return `/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: ${number}
  Name: ${title}
  Problem: https://onlinejudge.org/external/${((number / 100) | 0)}/${number}.pdf
  Language: ${lang}

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/`;
}

function makePyComment(number, title, lang) {
  return `##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: ${number}
##  Name: ${title}
##  Problem: https://onlinejudge.org/external/${((number / 100) | 0)}/${number}.pdf
##  Language: ${lang}

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com`;
}
