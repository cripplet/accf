package main

import(
  proto "github.com/golang/protobuf/proto"
  pb "github.com/cripplet/accf/protos"
)

func main() {
  println(proto.Marshal)
  p := pb.Person{
      Id: 1234,
      Name: "John",
      Email: "j@j.com",
      Phones: []*pb.Person_PhoneNumber{
        {Number: "123", Type: pb.Person_HOME},
      },
  }
  println(p.Id)
}
