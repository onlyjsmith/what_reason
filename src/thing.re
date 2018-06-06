let x: string = [%bs.raw {| 'well-typed' |}];

Js.log(x ++ " back in reason land!");