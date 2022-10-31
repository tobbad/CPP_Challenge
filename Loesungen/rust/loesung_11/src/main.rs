//extern crate getopts;
//use getopts::Options;
use std::env;
use lib::{to_roman, get_u64_parameter};

fn main(){
    let arg1 = env::args().nth(1);
	let number = get_u64_parameter(arg1.unwrap());
	println!("{}", number);
	let n_str = to_roman(number);
	println!("{}", n_str);

}

