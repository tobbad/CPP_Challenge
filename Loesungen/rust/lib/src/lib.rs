use std::io::stdin;
use std::io;
use std::str;
use rand;
use rand::Rng;
use std::fmt::Display;
use std::{env, fs};
use walkdir::WalkDir;

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

pub fn get_u32_parameter(parameter:String)->u32
{

	let res=parameter.trim().parse::<u32>().unwrap();
	// println!("Return {} ", res);
	res
}

pub fn get_u64_parameter(parameter:String)->u64
{

	let res=parameter.trim().parse::<u64>().unwrap();
	// println!("Return {} ", res);
	res
}

pub fn get_input(prompt: &str) -> String{
    println!("{}",prompt);
    let mut input = String::new();
    match io::stdin().read_line(&mut input) {
        Ok(_goes_into_input_above) => {},
        Err(_no_updates_is_fine) => {},
    }
    input.trim().to_string()
}

pub fn get_usize_parameter(parameter:String)->usize
{

	let res=parameter.trim().parse::<usize>().unwrap();
	// println!("Return {} ", res);
	res
}

pub fn get_u16_parameter(parameter:String)->u16
{

	let res=parameter.trim().parse::<u16>().unwrap();
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
	//let i=2;
	let uplim = (num as f64).sqrt() as u64+1;

	for i in 2..uplim
	{
		if num%i == 0
		{
			if i==num/i
			{
				result+= i;
			}
			else
			{
				result += i+num/i;
			}
		}
	}
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


pub fn  print_narcissistics() -> ()
{
	for  i in 1..9
	{
		for j in 1..9
		{
			for k in 1..9
			{
				let abc =100*i+10*j+k;
				let arm = i*i*i+j*j*j+k*k*k;
				if abc==arm
				{
					println!("{}", arm);
				}
			}
		}
		//std::cout << i << std::endl;
	}
}
pub fn prime_factors(mut number :u64) -> Vec<u64> 
{
	let mut factors: Vec<u64> =  Vec::new();
	let uplim = (number as f64).sqrt() as u64+1;
	while number%2==0 
	{
		factors.push(2);
		number /= 2;
	}
			
	for i in 3..uplim
	{
		while number%i==0
		{
			factors.push(i);
			number /= i;
		}
	}
	if number>2
	{
		factors.push(number);
	}

	return factors
}

pub fn gray_encode(number:u8) -> u8 {
	number ^ (number>>1)
}

pub fn gray_decode(mut gray:u8)  -> u8{
	for bit in (2..7).rev()
	{
		let bitmask = 1<<bit;
		if (gray &bitmask)==bitmask
		{
			gray ^= bitmask>>1;
		}
	}
	gray
}

pub fn to_binary(num:u8) -> String
{
	let mut ret = String::new();
	for n in (0..8).rev()
	{
		if num&(1<<n)==1<<n
		{
			ret += "1";
		} else {
			ret += "0";
 		}
	}
	ret
}

pub fn print_header(n:u8) -> ()
{
	match n
	{
		0 => println!("Number\tBinary\tGray\tDecoded"),
		1 => println!("------\t------\t----\t-------"),
		_ => println!(""),
	}
	
}
#[derive(Debug)]
struct STable {
       value: u64,
       string: String,
}



pub fn to_roman(mut number:u64) -> String
{
	let table = vec![
		STable{ value:1000, string:String::from("M" )},STable{ value:900, string:String::from("CM" )},
		STable{ value:500, string:String::from("D" )} ,STable{ value:400, string:String::from("CD" )},
		STable{ value:100, string:String::from("C" )} ,STable{ value:90, string:String::from("XC" )},
		STable{ value:50,string:String::from("L" )}  ,STable{ value:40, string:String::from("XL" )},
		STable{ value:10, string:String::from("X" )}  ,STable{ value:9, string:String::from("IX" )},
		STable{ value:5, string:String::from("V" )}   ,STable{value:4, string:String::from("IV" )},
		STable{ value:1, string:String::from("I")}
	];
	let mut res = String::new();
	for item in &table
	{
		
		while number >= item.value
		{
			number -= item.value;
			res += &item.string;
		}
		
	}
	res
}
        
// Implement cache for following function
pub fn longest_collatz(limit:usize) -> (usize, usize)
{
    let mut cache=vec![0; limit+1];
    let mut length:usize = 0;
    let mut number:usize = 0;
    for i in 2..limit+1
    {
        let mut n = i;
        let mut steps:usize=0;
        while n != 1 && n>=i
        {
            if n%2 == 0
            {
                n=n/2;
            } 
            else 
            {
                n = 3*n+1;
            }
            steps = steps+1;
        }
        cache[i] = steps + cache[n];
        if cache[i]>length
        {
            length = cache[i];
            number = i;
        }
        
    }
    (number,length)
}

pub fn compute_pi(samples:u32) -> f64
{
    let mut rng = rand::thread_rng();
    let mut hit = 0;
    for _i in 0..samples
    {
        let x = rng.gen::<f64>();
        let y = rng.gen::<f64>();
        if (1 as f64) > x*x + y*y
        {
            hit = hit+1; 
        }
        
    }
    4.0* hit as f64 /samples as f64

}

pub fn validate_isbn_10(isbn:String) -> bool
{
    let mut sum =0;
    if isbn.chars().count() == 10
    {
        let mut w = 10;
        for c in  isbn.chars()
        {
            if ! c.is_ascii_digit()
            {
                println!("{} is not numeric", c);
                return false
            }
            //println!("Check {}", c.to_digit(10).unwrap());
            sum = sum+w*(c.to_digit(10).unwrap());
            w = w-1; 
        }
    } 
//    else 
//    {
//        println!("Not correct length");
//    }
    
    (sum%11)==0
    
}

pub struct Matrix 
{
    xsize: u8,
    ysize:u8,
    pub data: Vec<Vec<i32>>,
}

impl Matrix
{
    pub fn new(xsize:u8, ysize:u8) -> Matrix  {
        Matrix {
            xsize: xsize,
            ysize:ysize,
            data :{
				let mut t = Vec::new();
				for _x in 0..ysize
				{
					let mut t2 = Vec::new();
					for _y in 0..xsize
					{
						t2.push(0i32);
					}
					t.push(t2);
				}
				t
            },
        }
    }
    pub fn set(&mut self, vec: &[i32])
    {
        let arr_size:usize  =  self.data.iter().map(Vec::len).sum();
        let max = if vec.len()>=arr_size
        {
			arr_size
        }
        else
        {
			0
        };
        for idx in 0..max
        {
			 let i = idx/self.xsize as usize;
			 let j = idx%self.ysize as usize;
			 self.data[i][j] = vec[idx];
			 self.data[i][j] = vec[idx];
        }
    }

	pub fn fill(&mut self, val:i32)
	{
		for i in 0..self.ysize as usize as usize
		{
			for j in 0..self.xsize as usize
			{
				self.data[i][j]=val;
			}

		}

	}

	pub fn swap(&mut self, other: &mut Matrix )
	{
		for i in 0..self.ysize as usize as usize
		{
			for j in 0..self.xsize as usize
			{
				let s = self.data[i][j];
				let o = other.data[i][j];
				self.data[i][j] = o;
				other.data[i][j] = s;
			}

		}

	}
}

impl Display for Matrix
{
    fn fmt(&self, f: &mut std::fmt::Formatter,) -> std::fmt::Result
    {

        let mut res = String::new();
        res+= "[\n";
        for  i in 0..self.ysize as usize
        {
            //res += format!("  [ {}", self.data[i]);
            for j  in 0..self.xsize as usize
            {
				if j==0
				{	
					res += &format!(" [");
				}
                let val = self.data[i][j];
                 res += &format!("{} ", val);
            }
            res+= "]\n";
        }
        res += "]";
        write!(f, "{}", res)
    }

}

fn factorial(n:u8) -> u32
{
    let mut  p:u32=1;
    for i in 1..n+1
    {
        p=p*(i as u32);
    }
    p
}

fn binomial_koeffizient(n:u8, k:u8) -> u32
{
    if k>n
    {
        0
    }
    else {
        let zaehler = factorial(n as u8);
        let nenner = factorial(k as u8)*factorial((n-k) as u8);
        //println!("{} {} {} {} {}", n, k,zaehler,nenner,zaehler/nenner);
        zaehler/nenner

    }
}
    

pub fn pascal_dreieck(line_cnt:u8) -> Vec<String>
{
    let mut res = Vec::new();
    
    for n in 0..line_cnt
    {
        let intend = (line_cnt<<1)-2*n+1;
        let mut line = String::from(" ").repeat(intend as usize);
        for k in 0..n+1
        {
            let k = binomial_koeffizient(n,k);
            line =line+&format!("{:4}",k);
        }
        res.push(line);
    }
    res 
}

fn print_type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>())
}

pub fn recursive_size(root_folder:&str) -> Vec<(&str, usize)>
{
	let mut res: Vec<(&str, usize)> = Vec::new();
	for entry in WalkDir::new(root_folder)
		.follow_links(true)
		.into_iter()
		.filter_map(|e| e.ok()) {
		let f_name = match entry.file_name().to_str()
        {
            Some(path) => path,
            _ => "Nope",
            
        };
        print_type_of(&f_name);
		//res.append(f_name);
		println!("{:?}", &f_name);
		//res.push((&f_name, 1));
	}
	res
}

