// Room: /inherit/room/cunyangdaoguan.c
inherit ROOM;
int do_put(string arg);
void create()
{
        set("short", "��������");
        set("long", @LONG
ֻ��ǰ��һ��������׵��ͱڣ���һ����ɽ�ƽ���һС���ۣ�������ʮ���ƾɣ�����
ʯ�Ž����ţ��Ŷ���ʯ���Ͽ��š��������ۡ��ĸ�ģ���Ĵ��֡�
LONG
);
        set("exits", ([ 
  "east" : __DIR__"houzhiwangyu",
]));
    set("item_desc", ([
        "men" : 
"    ���ȿ���������ƾ��ʯ�š����������Զ�������ѳ�������̦��
����Ȼ���Կ���������һ���ݵ�ӡ�ۡ�\n",
       "ʯ��" : 
"    ���ȿ���������ƾ��ʯ�š����������Զ�������ѳ�������̦��
����Ȼ���Կ���������һ���ݵ�ӡ�ۡ�\n",
       "ӡ��" :"��ӡ���е�������Ƶ���״��\n",
])); 
        setup();
}
void init()
{
    add_action("do_put", "put");
    
}
int do_put(string arg)
{
        object me,ob;
        object room;
        me = this_player();
        if (!objectp(ob=present("ling pai",me)))
            return notify_fail("������û������������\n");
        if( arg=="ling in ӡ��" || arg=="ling pai in ӡ��") {
            if (!( room = find_object(__DIR__"daoguan")) )
                room = load_object(__DIR__"daoguan");
            message_vision("$N�������е�"+ob->query("name")+"���ӡ�ۡ�\n",me);
            message("vision","��ʱͻȻ����һ����ص�������ʯ�Ŵ��ˣ�¶��һ������\n",this_object());
            message("vision", "��ʱͻȻ����һ����ص�������ʯ�ű��˴��ˡ�\n",room);
            set("exits/north",base_name(room));
            room->set("exits/south",base_name(this_object()));
            destruct(ob);
            call_out("close_door",10,room);
        return 1;
      }
      return 0;
}
void close_door(object room)
{
      message("vision","ͻȻ���顱��һ����ʯ���ֹص������ġ�\n",this_object());
      message("vision","ͻȻ���顱��һ����ʯ���ֹص������ġ�\n",room);
      delete("exits/north");
      room->delete("exits");
        room->set("do_prize",0);
}

