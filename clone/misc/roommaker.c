// roommaker.c
// for ESLib

#define RMK_VERSION "(v2.0)"
#include <ansi.h>
inherit ITEM;

string *special_props = ({
    "short", "long" });
nosave mapping map_dirs = ([
    "north":        "北",
    "south":        "南",
    "east":         "东",
    "west":         "西",
    "northup":      "北边往上",
    "southdown":        "南边往下",
    "southup":      "南边往上",
    "northdown":        "北边往下",
    "eastup":       "东边往上",
    "westdown":     "西边往下",
    "westup":       "西边往上",
    "eastdown":     "东边往下",
    "northeast":        "东北",
    "northwest":        "西北",
    "southeast":        "东南",
    "southwest":        "西南",
    "up":           "上",
    "down":         "下",
    "out":          "外",
]);

int save_room_file(string yn, string file, string str);

void create()
{
    set_name("房间编辑器" + RMK_VERSION, ({ "roommaker", "maker" }) );
    set_weight(100);
    set("unit", "个" );
    set("long", @LONG
这是一个用来「快速」制造房间的工具，帮助时间不多或有严重  lag 的巫师
利用线上输入制造简单的房间，不过如果你想提高自己区域房间的品质，最好
不要太依赖这个东西，你可以使用以下几个指令：

mkroom <房间档名>
    造出一个「空」房间，之後你可以 goto 到这个房间用 rset 设定房间的
    叙述或属性。

rset <房间属性> <属性内容>
    设定你目前所在房间的属性，如 short,outdoors,valid_startroom等。

rdelete <房间属性>
    删除你目前所在房间的属性，如rset设定的属性和long,objects,exits等。

long
    设定你目前所在房间的描述属性。

connect <方向> <房间档名>||<none>
    将你目前所在的房间连接一个出口到另一个房间，房间档名=none则删除这个方向。

addobj <NPC档名> <数量>
    设定你目前所在房间的NPC和其数量。

saveroom
    将你目前所在的房间存档。
LONG
    );
}


void init()
{
    if( wizardp(environment()) ) {
        seteuid(getuid(environment()));
        add_action("do_mkroom", "mkroom");
        add_action("do_rset", "rset");
        add_action("do_delete", "rdelete");
        add_action("do_connect", "connect");
        add_action("do_saveroom", "saveroom");
        add_action("do_addobj", "addobj");
        add_action("do_long", "long");
    }
}

int do_mkroom(string arg)
{
    string file, dir;

    if( !arg ) return notify_fail("指令格式：mkroom <房间档名> [<方向>]\n");
    if( sscanf(arg, "%s %s", file, dir)!=2 )
        file = arg;
    seteuid(geteuid(this_player()));
    file = resolve_path(this_player()->query("cwd"), file) + ".c";
    if( file_size(file)!=-1 )
        return notify_fail("档案 " + file + " 已经存在了。\n");
    if( !write_file(file, @ROOM_CODE
// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", "空房间");
    set("long", "这是一间什麽也没有的空房间。\n");
    setup();
    replace_program(ROOM);
}
ROOM_CODE
) ) return notify_fail("你没有写入档案(" + file +")的权利。\n");
    message_vision("只听到$N左右手一撑，「哔」的一声，你觉得这个世界又变大了一点。\n", this_player());
    return 1;
}

int do_rset(string arg)
{
    string prop, str;
    mixed data;

    if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
        return notify_fail("指令格式：rset <房间属性> <属性内容>\n
\t rset short           （设定这间房间的简略描述）\n
\t rset outdoors        （设定这里是户外属性）\n
\t rset valid_startroom （设定这里是下次连线开始的属性）\n
\t 其他的如：rset no_fight rset no_magic 等...\n\n");
    write("设置"+prop+"的属性为"+str);
    if( sscanf(str, "%d", data)!=1 )
        data = str;
    environment(this_player())->set(prop, str);
    write("...Ok.\n");
    return 1;
}

int do_delete(string arg)
{

    if( !arg)
        return notify_fail("指令格式：rdelete <房间属性>\n");
    environment(this_player())->delete(arg);
    write("Ok.\n");
    return 1;
}
int do_long()
{
    string arg;
    arg="";
    write("讯息可以有好几行，行首用 . 表示结束。\n");
    write("————————————————————————————————————\n");
    input_to("get_long",arg);
    return 1;
}
int get_long(string msg,string arg)
{
    if( msg=="."){
        environment(this_player())->set("long", arg);
        write("Ok.\n");
        return 1;
    }
    arg+=msg+"\n";
    input_to("get_long",arg);
    return 1;
}

int do_connect(string arg)
{
    mapping exits;
    int i;
    object room;
    string dir, file,*dirs;

    exits = environment(this_player())->query("exits");
    if( !arg || sscanf(arg, "%s %s", dir, file)!=2 ){
        dirs=sort_array( keys(map_dirs),(: strcmp :) );
        dir=" 一般情况下，使用的出口方向有以下几种: \n";
        for (i=0;i<sizeof(map_dirs);i++)
            dir+=sprintf("%-12s \t %-12s \n",dirs[i],map_dirs[dirs[i]]);
        if( mapp(exits) ){
            dir+="这里的出口有：\n";
            dirs=keys(exits);
            for (i=0;i<sizeof(exits);i++){
                if (!room=find_object(exits[dirs[i]]))
                room=load_object(exits[dirs[i]]);
            if (room)   dir+=sprintf(BOLD"\t%-12s"+NOR+YEL+" --> "+CYN+"%s"+RED+"(%s) \n"+NOR,dirs[i],room->query("short"),exits[dirs[i]]);
            else    dir+=sprintf(BOLD"\t%-12s"+NOR+YEL+" --> "+RED+"没有正常出口。\n"+NOR,dirs[i]);
            }
        }
        return notify_fail(dir+"\n指令格式：connect <方向> <房间档名>||<none>\n");
    }
    if (file=="none"){
        environment(this_player())->delete("exits/"+dir);
        write("删除出口...Ok.\n");
        return 1;
    }
    file = resolve_path(this_player()->query("cwd"), file);
        if (!room=find_object(file))
        room=load_object(file);
    if (!room)  return notify_fail("还没有"+file+"这个房间...\n");
    if( mapp(exits) )
        exits[dir] = file;
    else
        environment(this_player())->set("exits", ([ dir: file ]) );
    switch(dir){
        case "north"    :   dir="south";break;
        case "northwest":   dir="southeast";break;
        case "northeast":   dir="southwest";break;
        case "northdown":   dir="southup";break;
        case "northup"  :   dir="southdown";break;
        case "south"    :   dir="north";break;
        case "southwest":   dir="northeast";break;
        case "southeast":   dir="northwest";break;
        case "southdown":   dir="northup";break;
        case "southup"  :   dir="northdown";break;
        case "west" :   dir="east";break;
        case "westup"   :   dir="eastdown";break;
        case "westdown" :   dir="eastup";break;
        case "eastup"   :   dir="westdown";break;
        case "eastdown" :   dir="westup";break;
        case "east" :   dir="west";break;
        case "up"   :   dir="down";break;
        case "down" :   dir="up";break;
        case "out"  :   dir="enter";break;
        case "enter"    :   dir="out";break;
        default     :   dir="";break;
    }
    if (dir!=""){
        exits = room->query("exits");
        file=base_name(environment(this_player()));
        if( mapp(exits) )
            exits[dir] = file;
        else
        room->set("exits", ([ dir: file ]) );
    }
    write("Ok.\n");
    return 1;
}
int do_addobj(string arg)
{
    mapping objects;
    string file,*files;
    int amount;

    objects = environment(this_player())->query("objects");
    if( !arg || sscanf(arg, "%s %d", file,amount)!=2 ){
    if( mapp(objects) )
        files=keys(objects);
        file=" 这个房间的NPC有：\n";
        for (amount=0;amount<sizeof(objects);amount++)
            file+=sprintf(BOLD+"%20s %10s个\n"+NOR,files[amount]->short(),chinese_number(objects[files[amount]]) );
        return notify_fail(file+"\n指令格式：addobj <NPC档名> <数量>\n");
    }
    if ( file_size(file+".c")<0 )   file = resolve_path(this_player()->query("cwd"), file);
    if ( file_size(file+".c")<0 )
        return notify_fail("没有这个物件......\n");
        if (amount==0){
            environment(this_player())->delete("objects/"+file);
            write("删除NPC，Ok.\n");
            return 1;
        }
    if( mapp(objects) )
        objects[file] = amount;
    else
        environment(this_player())->set("objects", ([ file: amount ]) );
    write("Ok.\n");
    return 1;
}
int update(object me, string file)
{
        int i;
        object obj, *inv;
        string err;

        seteuid( geteuid(me) );

        if( !sscanf(file, "%*s.c") ) file += ".c"; 

        if( file_size(file)==-1 )
                return notify_fail("没有这个档案。\n");

        if (obj = find_object(file)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB )
                                return notify_fail("你不能在 VOID_OB 
里重新编译 VOID_OB。\n");
                        inv = all_inventory(obj);
                        i = sizeof(inv);
                        while(i--)
                                if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
                                else inv[i] = 0;
                }
                destruct(obj);
        }

        if (obj) return notify_fail("无法清除旧程式码。\n");

    write("重新编译 " + file + "：");
        err = catch( call_other(file, "???") );
        if (err)
                printf( "发生错误：\n%s\n", err );
        else {
                write("成功！\n");
                if( (i=sizeof(inv)) && (obj = find_object(file))) {
                        while(i--)
                                if( inv[i] && userp(inv[i]) ) 
inv[i]->move(obj, 1);
                }
        }
                
        return 1;
}


int do_saveroom(string arg)
{
    object env;
    string str, *name, file;
    mapping prop;
    int i;

    env = environment(this_player());
    file = file_name(env) + ".c";
    str = "// Room: " + file +@ROOM_CODE

// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
ROOM_CODE
;
    str += sprintf("\tset(\"short\", %O);\n", env->query("short") );
    str += sprintf("\tset(\"long\", @LONG\n%sLONG\n);\n", env->query("long") );
    prop = env->query_entire_dbase();
    name = keys(prop);
    for(i=0; i<sizeof(name); i++) {
        if( member_array(name[i], special_props)!=-1 ) continue;
        str += sprintf("\tset(\"%s\", %O);\n", name[i], prop[name[i]] );
    }
    str += "\n\tsetup();\n\treplace_program(ROOM);\n}\n";

    // Replace current directory with __DIR__ macro to make relocatable code.
    i = strlen(file)-1;
    while( (i > 0) && (file[i]!='/')) i--;
    if( i>0 ) {
        write("目前目录：" + file[0..i] + " 以 __DIR__ 取代。\n");
        str = replace_string(str, "\"" + file[0..i], "__DIR__\"");
    }

    if( file_size(file)!=-1 ) {
        write("档案 " + file + " 已存在，要删除旧档吗？[y/n]");
        input_to("save_room_file", file, str);
        return 1;
    }

    return save_room_file("y", file, str);
}

int save_room_file(string yn, string file, string str)
{
    if( strlen(yn)<1 || yn[0]!='y' ) return 1;

    rm(file);
    write("存档 " + file + "....");
    if( write_file(file, str) ) {
        write("Ok.\n");
        return update(this_player(),file);
    } else
        return notify_fail("你没有写入这个档案(" + file + ")的权利。\n");
}

void owner_is_killed() { destruct(this_object()); }
