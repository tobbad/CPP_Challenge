//use std::io::*;
use lib::{get_int_fromcl, prime_factors};

fn main(){
	let limit = get_int_fromcl(&String::from("Upper limit? "));
	let res = prime_factors(limit);
	println!("{:?}",res);
}
