use std::io::*;
use std::process::*;
use loesung_07::{get_int_fromcl, print_amicables};

fn main(){
	let limit = get_int_fromcl(&String::from("Upper limit? "));
	print_amicables(limit);
}
