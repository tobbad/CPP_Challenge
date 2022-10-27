//extern crate getopts;
//use getopts::Options;
//use std::env;
use loesung_11::{to_roman, get_int_fromcl};

fn main(){
	let number = get_int_fromcl("Number?");
	let n_Str = to_roman(number);
	println!("{}", n_Str);
}
