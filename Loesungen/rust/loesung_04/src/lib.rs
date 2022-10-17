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

pub fn is_prim(num:u64) -> bool
{
	//println!("{}", num);
	if num <= 3
	{
		return num>1
	} else {
		let uplim = (num as f64).sqrt() as u64+1;
		if (num%2==0)||(num%3==0){
			return false
		} else {
		//println!(" check up to {}", uplim);
			for i in 2..uplim
			{
				//println!("{}",i);
				if num%i == 0 {
					//println!("{} is dividor ",i); 
					return false
				}
				if num %(i+2)==0 {
					//println!("{} is dividor ",i+2); 
					return false
				}
			}
		}
	}
	//println!("{} is prime", num);
		
	return true
}

pub fn sum_proper_divisors(num:u64) -> u64
{
	let mut result =1;
	let mut i=2;
	let uplim = (num as f64).sqrt() as u64;

	for i in 2..uplim
	{
		if num%i==0
		{
			if i==num%i
			{
				result+=i;
			}
			else
			{
				result+=i+num/i;
			}
		}
	}
	//println!("Sum proper divisors{} ", result);
	result
}

pub fn print_abundant(limit:u64) -> u64{
	let mut number = 10; 
	while  number<limit
	{
		let sum = sum_proper_divisors(number);
		if sum>number{
			println!("Abundance {} is prime", sum-number);
			break 
		}
		number += 1;
	}
	number
}

pub fn print_amicables(limit:u64) -> u64{
	let mut number=4;
	while  number<=limit
	{
		let sum1 = sum_proper_divisors(number);
		if sum1 < limit
		{
			let sum2 = sum_proper_divisors(sum1);
			if (sum2==number) && (number!=sum1)
			{
				println!("{} ;{}", sum1, sum2);
			}
		}
		number+=1;
	}
	number
}
