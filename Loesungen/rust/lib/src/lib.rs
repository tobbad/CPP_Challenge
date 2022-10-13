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

	if h != 0
	{
		a*(b/h)
	} else  {
		0
	}
}

fn inc(i:u64) -> u64
{
	i+1
}

pub fn is_prim(num:u64) -> bool
{
	//println!("{}", num);
	if num <= 3
	{
		num>2
	} else {
		let uplim = (num as f64).sqrt() as u64;
		//println!(" check up to {}", uplim);
		for i in 2..uplim
		{
			//println!("{}",i);
			if num%i == 0 {
				//println!("{} is dividor ",i); 
				return false;
			}
			if num %(i+2)==0 {
				//println!("{} is dividor ",i+2); 
				return false;
			}
		}
		//println!("{} is prime", num);
		
		return true;
	}
}