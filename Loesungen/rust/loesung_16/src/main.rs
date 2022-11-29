use network::{IPV4,string_to_u32 };
use lib::{get_input};

fn main(){
    let ps  = get_input("IP 1: "); // This is a String
    let ipa = string_to_u32(ps);
    let ip1 = IPV4::new(ipa);
    let ps  = get_input("IP 2: "); // This is a String
    let ipa = string_to_u32(ps);
    let ip2 = IPV4::new(ipa);
    println!("{:?} to {:?}", ip1, ip2);
    for i in ip1.to_u32()..ip2.to_u32()
    {
        let ip = IPV4::new(i);
        println!("{}", ip);
    }
    println!("{} {}", ip1, ip2);

}

