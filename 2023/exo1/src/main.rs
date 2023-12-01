use std::fs;

fn main() {
    let content = fs::read_to_string("input").expect("This should have opened a file");

    let sum = part1(content.clone());
    println!("result: {}", sum);
    println!("expected: 55607");

    let sum = part2(&content);
    println!("{}", sum);
}

fn part1(content: String) -> u32 {
    let mut sum: u32 = 0;
    let mut last: u8 = 0;
    let mut first: u8 = 0;

    for &c in content.as_bytes() {
        if c.is_ascii_alphabetic() {
            continue;
        } else if c == b'\n' {
            sum += ((first - b'0') * 10 + (last - b'0')) as u32;
            first = 0;
            last = 0;
        } else if first == 0 {
            first = c;
            last = c;
        } else {
            last = c;
        }
    }

    sum
}

fn part2(content: &str) -> u32 {
    content.split("\n").map(|s| parse_line(s)).sum()
}

fn parse_line(line: &str) -> u32 {
    let l1 = [
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    ];

    let mut first_index = 100000;
    let mut first:u32 = 0;
    let mut last_index = 0;
    let mut last:u32 = 0;

    for i in 0..9 {
        let left_index = line.find((b'1' + i) as char);
        if left_index != None && left_index.unwrap() < first_index {
            first_index = left_index.unwrap();
            first = i as u32;
        }

        let left_index = line.find(l1[i as usize]);
        if left_index != None && left_index.unwrap() < first_index {
            first_index = left_index.unwrap();
            first = i as u32;
        }

        let right_index = line.rfind((b'1' + i) as char);
        if right_index != None && right_index.unwrap() > last_index {
            last_index = right_index.unwrap();
            last = i as u32;
        }

        let right_index = line.rfind(l1[i as usize]);
        if right_index != None && right_index.unwrap() > last_index {
            last_index = right_index.unwrap();
            last = i as u32;
        }
    }
    first * 10 + last
}
