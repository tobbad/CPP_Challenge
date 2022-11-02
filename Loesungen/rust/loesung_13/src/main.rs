use std::env;
use lib::{compute_pi,get_u32_parameter};

fn main(){
    let arg1 = env::args().nth(1);
	let number = get_u32_parameter(arg1.unwrap());
	println!("{}", number);
    for _i in 0..10
    {
        let a = compute_pi(number);
        println!("{:?}", a);
    }

}

