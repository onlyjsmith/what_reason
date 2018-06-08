// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var Json = require("rex-json/./src/Json.js");

var data = "\n  {\n    \"some\": \"json\", // with a comment!\n    \"more\": [1,3,],\n    /* also\n    multi-line comment */\n    \"this\": {\n      \"object\": {\n        \"is\": {\n          \"really\": \"nested\"\n        }\n      }\n    },\n    \"nested\": [{\n      \"and\": [1,2,{\"stuff\": 5}]\n    }, {\"and\": [3,4,{\"stuff\": 6}]}], // trailing commas!\n  }\n  ";

var json = Json.parse(data);

var simple = Json.get("some", json);

var stuff = Json.Infix[/* |?> */2](Json.Infix[/* |?> */2](Json.Infix[/* |?> */2](Json.Infix[/* |?> */2](Json.Infix[/* |?> */2](Json.get("nested", json), (function (param) {
                        return Json.nth(1, param);
                      })), (function (param) {
                    return Json.get("and", param);
                  })), (function (param) {
                return Json.nth(2, param);
              })), (function (param) {
            return Json.get("stuff", param);
          })), Json.number);

var nestedString = Json.Infix[/* |?> */2](Json.getPath("this.object.is.really", json), Json.string);

var otherNestedString = Json.Infix[/* |?> */2](Json.getPath("some", json), Json.string);

var str = Json.stringify(json);

console.log(stuff, nestedString, otherNestedString);

exports.data = data;
exports.json = json;
exports.simple = simple;
exports.stuff = stuff;
exports.nestedString = nestedString;
exports.otherNestedString = otherNestedString;
exports.str = str;
/* json Not a pure module */