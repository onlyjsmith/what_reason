/* Decoding a fixed JSON data structure using Json.Decode */
let mapJsonObjectString = (f, decoder, encoder: int => Js.Json.t, str) => {
  let json = Json.parseOrRaise(str);
  Json.Decode.(dict(decoder, json))
  |> Js.Dict.map((. v) => f(v))
  |> Js.Dict.map((. v) => encoder(v))
  |> Json.Encode.dict
  |> Json.stringify;
};

let sum = Array.fold_left((+), 0);

/* prints `{ "foo": 6, "bar": 24 }` */
Js.log @@
mapJsonObjectString(
  sum,
  Json.Decode.(array(int)),
  Json.Encode.int,
  {|
      {
        "foo": [1, 2, 3, 4],
        "bar": [9, 8, 7]
      }
    |},
);

{
  /* Error handling */
  let json = {|{ "y": 42 } |} |> Json.parseOrRaise;
  switch (Json.Decode.(field("x", int, json))) {
  | x => Js.log(x)
  | exception (Json.Decode.DecodeError(msg)) => Js.log("Error:" ++ msg)
  };
};