// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var New = require("./new.js");
var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");

var result = New.add(1, 2);

var other_result = New.subtract(3, 1);

function twoAdder(param) {
  return New.add(2, param);
}

var four = twoAdder(2);

var my_list = /* :: */[
  0,
  /* :: */[
    1,
    /* :: */[
      2,
      /* :: */[
        3,
        /* :: */[
          4,
          /* :: */[
            5,
            /* [] */0
          ]
        ]
      ]
    ]
  ]
];

var bigger_list = List.map(twoAdder, my_list);

console.log($$Array.of_list(bigger_list));

exports.result = result;
exports.other_result = other_result;
exports.twoAdder = twoAdder;
exports.four = four;
exports.my_list = my_list;
exports.bigger_list = bigger_list;
/* result Not a pure module */
