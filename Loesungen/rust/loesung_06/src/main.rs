use std::io::*;
use std::process::*;
use lib::{get_int_fromcl, sum_proper_divisors};

fn main(){
	println!("Abundant numbers");
	let limit = get_int_fromcl(&String::from("Upper limit? "));
	for i in 10..limit+1	{
		let sum = sum_proper_divisors(i);
		if sum>i
		{
			println!("{} ; {}",i, sum-i);
		}
		
	}
}
