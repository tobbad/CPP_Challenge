use std::io::stdin;
use std::str;

pub fn get_int_fromcl(question:&str)->u64
{

	println!( "{}", question);
	let mut input_string = String::new();
    stdin().read_line(&mut input_string)
    	.ok()
        .expect("Failed to read line");	
	let res=input_string.trim().parse::<u64>().unwrap();
	// println!("Return {} ", res);
	res
}

pub fn gcd(a:u64, b:u64) -> u64 
{
	if b==0
	{
		a
	} else {
		gcd(b,a%b)
	}
}

pub fn lcm(a:u64, b:u64) -> u64
{
	let h = gcd(a, b);
	if h==0
	{
		a*(b/h)
	} else  {
		0
	}
}