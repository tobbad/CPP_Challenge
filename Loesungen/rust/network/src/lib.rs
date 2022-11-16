use std::fmt::{Display};

#[derive(Debug)]
pub struct IPV4
{
    pub ip : [u8;4],
    ip_u32: u32,
}

enum input {
    String,
    [u8;4],
}


pub fn string_ip_v4(string:String) -> [u8;4]
{   let ss = string.split(".");
	let mut res: [u8;4]= [0,0,0,0];
    let mut idx = 0;
    for i in ss
    {
        //println!("{:?}{:?}",i,ipPart); 
        let ip_part = i.parse().unwrap();
        res[idx] = ip_part;
        idx = idx+1;
    }
    res
}

impl IPV4
{
    // pub fn new<>(new_ip: [u8;4])->  IPV4 
    // {
        // let ipu32= new_ip[0]<<24 + new_ip[1]<<16+ new_ip[2]<<8 + new_ip[3];
        // IPV4 {
            // ip: new_ip,
            // ipu32 : ipu32
        // }
    // }
    
    pub fn new(ip_str :String)->  IPV4 
    {
        let new_ip = string_ip_v4(ip_str);
        let new_ip_u32 = u32::from_be_bytes(new_ip);
        IPV4 {
            ip: new_ip,
            ip_u32 : new_ip_u32,
        }
    }
}

impl Display for IPV4
{
    fn fmt(&self, f: &mut std::fmt::Formatter,) -> std::fmt::Result
    {
        write!(f, "IP: {}.{}.{}.{} of {}", self.ip[0], self.ip[1], self.ip[2],self.ip[3], self.type_of())
    }
 
}