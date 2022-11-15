use network::{IPV4};
use lib::{string_to_u8_arr,get_input};

fn main(){
    let ps  = get_input("IP: "); // This is a String
    let ipa = string_to_u8_arr(ps);
    let ip = IPV4{
        ip: ipa,
    };
    println!("{:?}", ip);

}

