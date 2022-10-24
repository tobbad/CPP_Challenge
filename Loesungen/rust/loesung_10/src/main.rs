//use std::io::*;
//use std::process::*;
use loesung_10::{gray_encode, gray_decode,print_header,to_binary};

fn main(){
	print_header(0);
	print_header(1);
	for  n in 0..32
	{
		let enc = gray_encode(n);
		let dec = gray_decode(enc);
		println!("{}\t{}\t{}\t{}", n,to_binary(enc), to_binary(dec),dec );
	}
}
