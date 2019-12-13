//bye enter
inherit ROOM;
int do_open(string arg);
int do_close(string arg);
void create()
{
        set("short", "������ͷ");
        set("long",@LONG
�����ǰ����ľ�ͷ����������(door)�������ܳ¾ɣ���֪��ͨ��
���
LONG            
        );
        set("exits", ([
                "south" : __DIR__"andao2",
        ]));
        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        setup();
}
void init()
{
        add_action("do_open", "open");
        add_action("do_close", "close");
}
void close_door()
{
        object room;
        if(!( room = find_object("/d/city3/xiaoting")) )
              room = load_object("/d/city3/xiaoting");
        if(objectp(room))
        {
                delete("exits/east");
                  message("vision", "��Ȼ�䣬ˮ���ֿ���¶��һ����·��\n", this_object());
                room->delete("exits/west");
                  message("vision", "ˮ������Ȼ�����ˡ�\n", room);
        }
}
int do_close(string arg)
{
        if (!query("exits/east"))
                return notify_fail("�Ѿ��г�·�ˣ�\n");
        if (!arg || (arg != "door" && arg != "east"))
                return notify_fail("��Ҫ��ʲô��\n");
        message_vision("$N���˵�ͷ��\n", this_player());
        remove_call_out("close_door");
        call_out("close_door", 2);
        return 1;
}
int do_open(string arg)
{
        object room;
        if (query("exits/east"))
                return notify_fail("�Ѿ��г�·�ˣ�\n");
        if (!arg || (arg != "door" && arg != "east"))
                return notify_fail("��Ҫ��ʲô��\n");
        if(!( room = find_object("/d/city3/xiaoting")) )
              room = load_object("/d/city3/xiaoting");
        if(objectp(room))
        {
                set("exits/east","/d/city3/xiaoting");
                  message_vision("$N�����������Ŵ��˿�����\n", this_player());
                room->set("exits/west", __FILE__);
                  message("vision", "��Ȼ�䣬ˮ����ӿ���ְ��ź����ˡ�\n", room);
                remove_call_out("close_door");
                call_out("close_door", 5);
        }
        return 1;
}
string look_door(string arg)
{
        return "����һ���ƾɵ����š�\n";
}

