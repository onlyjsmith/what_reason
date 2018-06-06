let result = New.add(1, 2);

let other_result = New.subtract(3, 1);

let twoAdder = New.add(2);

let four = twoAdder(2);

let my_list = [0, 1, 2, 3, 4, 5];

let bigger_list = List.map(twoAdder, my_list);

Js.log(Array.of_list(bigger_list));
/* let () = { */
/* print_string("Hello world!"); */
/* print_string(string_of_int(result)); */
/* print_string(string_of_int(four)); */
/* print_newline(); */
/* }; */