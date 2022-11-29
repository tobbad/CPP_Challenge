use std::fmt::{Display};
use std::fmt::Error;
#[derive(Debug)]
pub struct IPV4
{
    ip_u32: u32,
}

pub fn string_ip_v4(string:String) -> [u8;4]
{   let ss = string.split(".");
	let mut res: [u8;4]= [0,0,0,0];
    let mut idx = 0;
    for i in ss
    {
        let ip_part = i.parse().unwrap();
//        println!("{:?} {:?} {}",i,ip_part, idx); 
        res[idx] = ip_part;
        idx = idx+1;
    }
    res
}

pub fn string_to_u32(ip_str:String) -> u32
{
    let ipu8 =string_ip_v4(ip_str);
    u32::from_be_bytes(ipu8)
}

impl IPV4
{
    pub fn new(new_ip:u32)->  IPV4 
    {
        IPV4{
            ip_u32 : new_ip
        }
    }
    
    pub fn steps_between(start:&Self, end:&Self) -> Result< (),u32> 
    {
        if  end.ip_u32 > start.ip_u32
        {
             end.ip_u32- start.ip_u32
        } else {
            Err("No Proper oder")
        }
    }
    
    pub fn to_u32(self:&IPV4) -> u32 {
        self.ip_u32
    }
    
    pub fn to_u8_4(self:&IPV4) -> [u8;4]
    {
        let mut res: [u8;4]= [0,0,0,0];
        for i in 0..3
        {
            res[i] = (self.ip_u32>>(3*8-i)) as u8;
        }
        res
    }
}

impl Display for IPV4
{
    fn fmt(&self, f: &mut std::fmt::Formatter,) -> std::fmt::Result
    {   
        let ip = self.to_u8_4();
        write!(f, "IP: {}.{}.{}.{} ({})", ip[0], ip[1], ip[2], ip[3], self.ip_u32)
    }
 
}