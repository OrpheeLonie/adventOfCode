use std::fs;

fn main() {
    let content = fs::read_to_string("input")
        .expect("This should have opened a file");

    let sum = parse_file(content);
    println!("{}", sum)
}

fn parse_file(content: String) -> u32 {
    let mut sum:u32 = 0;
    let mut last:u8 = 0;
    let mut first:u8 = 0;
    content.as_bytes()
        .iter()
        .filter(|&c| !c.is_ascii_alphabetic())
        .for_each(|&c| {
            if c == b'\n' {
                sum += ((first - b'0') * 10 + (last - b'0')) as u32;
                first = 0;
                last = 0;
            } else if first == 0 {
                first = c;
                last = c;
            } else {
                last = c;
            }
        });

    sum
}
