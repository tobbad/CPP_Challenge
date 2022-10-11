use std::io::*;
use loesung_02::{get_int_fromcl, gcd};

fn main(){
	let a = get_int_fromcl(&String::from("a? "));
	let b = get_int_fromcl(&String::from("b? "));
	let res = gcd(a, b);
	println!("gcd is {}",res);
}
