use network::{IPV4,string_ip_v4 };
use lib::{get_input};

fn main(){
    let ps  = get_input("IP: "); // This is a String
    let ipu8a = string_ip_v4(ps);
    let ip = IPV4::new(ipu8a);
    println!("{:?}", ip);
    //println!("{}", ip);

}

