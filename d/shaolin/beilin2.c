// Room: /d/shaolin/beilin2.c
// Date: YZC 96/01/19
inherit ROOM;
#include <ansi.h>
void check_trigger();
void close_passage();
void reset();
int do_push(string arg);
int do_say(string arg);
string look_tower();
string look_stone();
void create()
{
    set("short", "������");
    set("long", @LONG
������һ��Ƭ���֡���˵�Ǳ��֣���Ҫ������������ɮ��
�������(tower)��һ��������Լ�ж����˸ߣ��к�����ģ�
����ʯ�ģ��������䣬�����ĸ������Ϸ������ޣ�������ʫ��
�����������ν�����������������������ģ�Ҳ���������ģ�
��̬�׳ʡ�������������������ż��鱮(stone)���е�����
����ʫ��
LONG
    );
    set("exits", ([
        "east" : __DIR__"taijie",
    ]));
    set("outdoors", "shaolin");
    set("item_desc",([
        "tower"     :   (: look_tower :),
        "stone"     :   (: look_stone :),
    ]));
    setup();
}
void init()
{
    add_action("do_push", "push");
    add_action("do_pull", "pull");
    add_action("do_say", "say");
}
void check_trigger()
{
    object room;
    if( (int)query("up_trigger")==4
    &&  (int)query("down_trigger")==3
    &&  !query("exits/down") ) {
        message("vision", "������Ȼ������������������һ�໺���ƿ���"
            "����¶��һ���ڶ�������ڡ�\n", this_object() );
        set("exits/down", __DIR__"beilin3");
        if( !room = find_object(__DIR__"beilin3") )
            room=load_object(__DIR__"beilin3");
            room->set("exits/up", __FILE__);
            message("vision", "ͷ���ϵ�ʯ���Ȼ����������������¶��һ���������Ķ��ڡ�\nһ���̤��ʯ��ǽ����͹�˳������γ�һ�����ϵĽ��ݡ�\n",room );
        delete("poem_said");
        delete("up_trigger");
        delete("down_trigger");
        remove_call_out("close_passage");
        call_out("close_passage", 15);
    }
}
void close_passage()
{
    object room;
    if( !query("exits/down") ) return;
    message("vision", "������Ȼ�����������������������ƻ�ԭ����"
        "�����µĶ��ڸ�ס�ˡ�\n", this_object() );
    if( !room = find_object(__DIR__"beilin3") )
        room=load_object(__DIR__"beilin3");
    room->delete("exits/up");
    message("vision", "ͷ���ϵ�ʯ���Ȼ����������������\nǽ�ϵ�ʯ���ֻ��������˻�ȥ��������ʧ�ˡ�\n", room );
    delete("exits/down");
}
int do_pull(string arg)
{
    string dir;
    if( !arg || arg=="" ){
        write("��Ҫ�⶯ʲô��\n");
        return 1;
    }
    if (!(int)query("poem_said")){
        write("�����Ű⶯���ʯ������������̫����......\n");
        return 1;
    }
    if( arg=="stone" && (int)query("poem_said")==1 ) {
        write("�����Ű⶯���ʯ�������ֿ�������̧......\n");
        return 1;
    }
    if( sscanf(arg, "stone %s", dir)==1 && (int)query("poem_said")==1 ) {
        if( dir=="up" ) {
            message_vision("$N��ʯ������̧...����Ȼ������һ��ʯ�����ƻ�ԭλ��\n",
                this_player());
            add("up_trigger", 1);
            check_trigger();
            return 1;
        } else {
            write("��Ҫ��ʯ�������Ǹ�����\n");
            return 1;
        }
    }
}
int do_push(string arg)
{
    string dir;
    if( !arg || arg=="" ){
        write("��Ҫ�⶯ʲô��\n");
        return 1;
    }
    if (!(int)query("poem_said")){
        write("�����Ű⶯���ʯ������������̫����......\n");
        return 1;
    }
    if( arg=="stone" && (int)query("poem_said")==1 ) {
        write("�����Ű⶯���ʯ�������ֿ�������ѹ......\n");
        return 1;
    }
    if( sscanf(arg, "stone %s", dir)==1 && (int)query("poem_said")==1 ) {
        if( dir=="down" ) {
            message_vision("$N��ʯ������ѹ...����Ȼ������һ��ʯ�����ƻ�ԭλ��\n",
                this_player());
            add("down_trigger", 1);
            check_trigger();
            return 1;
        } else {
            write("��Ҫ��ʯ�������Ǹ�����\n");
            return 1;
        }
    }
}
int do_say(string arg)
{
    if( !arg || arg=="" ) return 0;
    if( arg=="�ϱ����ض����¼���;��" ) {
        write(YEL"\nֻ�����ܵķ�����ʯ������¡¡¡������������������������\n\n"NOR);
        add("poem_said", 1);
        return 0;
    }else{
        write("�������ʫ�� !\n");
        return 0;
    }
    return 0;
}
void reset()
{
    ::reset();
    delete("poem_said");
    delete("up_trigger");
    delete("down_trigger");
}
string look_tower()
{
    return
    "\n"
    "    ��������������������������������������������\n"
    "    ��������������������������������������������\n"
    "    ����������һ�������Ϥ�������ģ�����������\n"
    "    ��������������������������������������������\n"
    "    �����������ϱ����ض����¼���;�࣬����������\n"
    "    ��������������������������������������������\n"
    "    �����������ޱߴ������ɽ������֣�����������\n"
    "    ��������������������������������������������\n"
    "    ����������Ը�Դ˹��£�ׯ�Ϸ���������������\n"
    "    ��������������������������������������������\n"
    "    ��������������������������������������������\n"
    "\n���૵����˼��飬�޷��������еİ��\n"
    "\n\n��Ŀ��һɨ������ʯ�����µ������ƺ��е㲻һ���������(pull)����������\n";
}
string look_stone()
{
    return
    "\n"
    "    ��������������������������������������������\n"
    "    ��������������������������������������������\n"
    "    ��������������������������������������������\n"
    "    �����������峿����£������ո��֡�����������\n"
    "    ��������������������������������������������\n"
    "    ��������������ͨ�Ĵ���������ľ�����������\n"
    "    ��������������������������������������������\n"
    "    ����������ɽ�������ԣ�̶Ӱ�����ġ�����������\n"
    "    ��������������������������������������������\n"
    "    ���������������˾�ţ�Ω��������������������\n"
    "    ��������������������������������������������\n"
    "    ��������������������������������������������\n"
    "    ��������������������������������������������\n"
    "\n���૵����˼��飬�޷��������еİ��\n"
    "\n\n��Ŀ��һɨ������ʯ�����µ������ƺ��е㲻һ���������(push)����������\n";
}
