use network::{IPV4};
use lib::{get_input};

fn main(){
    let ps  = get_input("IP: "); // This is a String
    let ip = IPV4::new(ps);
    println!("{:?}", ip);
    println!("{}", ip);

}

