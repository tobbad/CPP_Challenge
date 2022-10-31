
use lib::get_int_fromcl;

fn main(){
	let mut summe:u64=0;
	let limite = get_int_fromcl(&String::from("Upper limit? "));
	for i in 0 .. limite+1	{
		if (i%3)==0 || (i%5)==0
		{
			summe += i;
			println!("Summ up {} to {}", i, summe);
		}
		
	}
	println!("Summe is {}",summe);
}
