use std::fmt::{Display};

#[derive(Debug)]
pub struct IPV4
{
    ip : [u8;4],
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

impl IPV4
{
    pub fn new(new_ip:[u8;4])->  IPV4 
    {
        let ip_u32_new:u32= u32::from_be_bytes(new_ip);
        IPV4{
            ip: new_ip,
            ip_u32 : ip_u32_new
        }
    }
    
}

impl Display for IPV4
{
    fn fmt(&self, f: &mut std::fmt::Formatter,) -> std::fmt::Result
    {
        write!(f, "IP: {}.{}.{}.{}", self.ip[0], self.ip[1], self.ip[2],self.ip[3])
    }
 
}