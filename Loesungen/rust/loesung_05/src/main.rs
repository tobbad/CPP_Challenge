use std::io::*;
use lib::{get_int_fromcl, is_prim};

fn main(){
	let limit = get_int_fromcl(&String::from("Upper limit? "));
	for i in 0..limit+1 
    {
		if is_prim(i) || is_prim(i+6)
		{
			println!("{};{}",i, i+6);
			//exit(0);
		}
		
	}
}
