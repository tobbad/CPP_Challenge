use std::io::*;
use std::process::*;
use lib::{get_int_fromcl, is_prim};

fn main(){
	let limit = get_int_fromcl(&String::from("Upper limit? "));
	for i in (0..limit+1).rev()	{
		if is_prim(i)
		{
			println!("Largest prime {}",i);
			//exit(0);
		}
		
	}
}
