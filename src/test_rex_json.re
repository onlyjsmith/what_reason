
let data = {|
  {
    "some": "json", // with a comment!
    "more": [1,3,],
    /* also
    multi-line comment */
    "this": {
      "object": {
        "is": {
          "really": "nested"
        }
      }
    },
    "nested": [{
      "and": [1,2,{"stuff": 5}]
    }, {"and": [3,4,{"stuff": 6}]}], // trailing commas!
  }
  |};
  let json = Json.parse(data);
  let simple = Json.get("some", json); /* == Some(String("json")) */
  
  open Json.Infix;
  
  let stuff = json
    |> Json.get("nested")
    |?> Json.nth(1)
    |?> Json.get("and")
    |?> Json.nth(2)
    |?> Json.get("stuff")
    |?> Json.number; /* == Some(5.) */
  
  /** Using a json path for nested objects */
  let nestedString = json
  |> Json.getPath("this.object.is.really")
  |?> Json.string; /* Some("nested") */

  let otherNestedString = json |> Json.getPath("some") |?> Json.string;
  
  let str = Json.stringify(json); /* back to a string */
  Js.log3(stuff, nestedString, otherNestedString);