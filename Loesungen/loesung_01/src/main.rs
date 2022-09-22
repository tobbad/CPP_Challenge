
use std::io;
fn main(){
	let limite=100;
	let summe:u64=0;
	for i in 0 .. limite	{
		let mut summe:u32=0;
		if (i%3)==0 && (i%5)==0
		{
			let summe= summe+i;
			println!("Summ up {} to {}", i, summe);
		}
		
	}
	println!("Summe is {}",summe);
}
