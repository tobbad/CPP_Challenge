use std::env;
use lib::{compute_pi,validate_isbn_10, get_sting_parameter};

fn main(){
    let arg1 = env::args().nth(1);
    isbn = get_sting_parameter(arg1);
	println!("{}", isbn);
    let a = validate_isbn_10(arg1);
    println!("{:?}", a);

}

