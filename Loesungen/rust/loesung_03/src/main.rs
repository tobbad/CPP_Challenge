use std::io::*;
use lib::{get_int_fromcl, lcm};

fn main(){
	let a = get_int_fromcl(&String::from("a? "));
	let b = get_int_fromcl(&String::from("b? "));
	let res = lcm(a, b);
	println!("lcm is {}",res);
}
