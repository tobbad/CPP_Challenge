use network::{IPV4,string_ip_v4 };
use lib::{get_input};

fn main(){
    let ps  = get_input("IP 1: "); // This is a String
    let ipa = string_ip_v4(ps);
    let ip1 = IPV4::new(ipa);
    let ps  = get_input("IP 2: "); // This is a String
    let ipa = string_ip_v4(ps);
    let ip2 = IPV4::new(ipa);
    println!("{:?} to {:?}", ip1, ip2);
    println!("{} {}", ip1, ip2);

}

