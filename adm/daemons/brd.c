
void create()
{
        seteuid(getuid());

}
void buildroom(object me,string s_title,string l_title, string dir,int rec)
{
mapping pairs = ([
        "north":                "south",
        "south":                "north",
        "east":                 "west",
        "west":                 "east",
        "northup":              "southdown",
        "southup":              "northdown",
        "eastup":               "westdown",
        "westup":               "eastdown",
        "northdown":            "southup",
        "southdown":            "northup",
        "eastdown":             "westup",
        "westdown":             "eastup",
        "northeast":            "southwest",
        "northwest":            "southeast",
        "southeast":            "northwest",
        "southwest":            "northeast",
        "up":                   "down",
        "down":                 "up"
]);
       
        string this_file;
        string my_file;
        string name;
        object myroom;
        string c_name;
        name = (string)me->query("id")+sprintf("%d",time());
        c_name = base_name(environment(me))+".c";
        this_file = read_file(c_name);
        this_file = replace_string(this_file,"set(\"exits\", ([",
"set(\"exits\", ([\n"+"\""+dir+"\""+" : \"/d/party/"+me->query("party/id")+"/"+name+"\",");   
        if(!write_file(c_name,this_file,1))
        return;

        environment(me)->set("exits/"+dir,"/d/party/"+me->query("party/id")+"/"+name);        
        // now the room we are in is done!
        switch(rec) {
        case 1:
        my_file = read_file("/clone/room/user_room.o");
        break;
        case 2:
        my_file = read_file("/clone/room/restroom.o");
        break;
        case 3:
        my_file = read_file("/clone/room/weaponroom.o");
        break;
        case 4:
        my_file = read_file("/clone/room/city.o");
        break;
        case 5:
        my_file = read_file("/clone/room/lianroom.o");
        break;
        case 6:
        my_file = read_file("/clone/room/menroom.o");
        break;
        }
        my_file = replace_string(my_file,
"set(\"exits\", ([",
"set(\"exits\", ([\n"+"\""+pairs[dir]+"\""+" : "+"\""+c_name+"\",");
        my_file= replace_string(my_file,"SHORT_TITLE",s_title);
         my_file= replace_string(my_file,"LONG_TITLE",l_title);
       if(me->query("party/id"))
        my_file= replace_string(my_file,"bigwiz7001",
        me->query("party/id"));
       my_file= replace_string(my_file,"SAVE_NAME",name);
       write_file("/d/party/"+me->query("party/id")+"/"+name+".c",my_file,1);
       write("�ɹ�����\n");
        me->add("created_room",1);
        switch(rec) {
        case 1:
        me->add("created_room",1);
        break;
        case 2:
        me->add("rest_room",1);
        break;
        case 3:
        me->add("weapon_room",1);
        break;
        case 4:
        me->add("xiucheng_room",1);
        break;
        case 5:
        me->add("lian_room",1);
        break;
        case 6:
        me->add("created_men",1);
        break;
        }
myroom=load_object("/d/party/"+me->query("party/id")+"/"+name);
myroom->set("owner",me->query("id"));
myroom->save();
me->save();
}

int touch_file(string name)
{
if(write_file(name," ",1))
return 1;
else return 0;
}

