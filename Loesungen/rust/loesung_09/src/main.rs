//use std::io::*;
use std::process::*;
use loesung_09::{get_int_fromcl, prime_factors};

fn main(){
	let mut limit = get_int_fromcl(&String::from("Upper limit? "));
	let res = prime_factors(limit);
	println!("{:?}",res);
}
