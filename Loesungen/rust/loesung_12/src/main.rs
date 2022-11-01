use std::env;
use lib::{longest_collatz, get_usize_parameter};

fn main(){
    let arg1 = env::args().nth(1);
	let number = get_usize_parameter(arg1.unwrap());
	println!("{}", number);
	let a = longest_collatz(number);
	println!("{:?}", a);

}

