//ROOM xuanbing.c
inherit ROOM;
void init();
int do_climb(object me);
int do_xia(object me);
    
void create()
{
        set("short","������");
    set("long",@LONG
���������ڹ��ĵط��� ����������һ��ǧ������(ice)������ð��˿
˿������ ������˺������ˣ��㲻�ɵô���һ��������
LONG
    );
    
        set("exits", ([
        "east" : __DIR__"changl13",
        ]));
    set("item_desc", ([
        "ice" : "����һ�������ɽ֮�۵�ǧ������,��˵������������°빦��.\n�����������(climb)��ȥ.\n",
        ]));
 setup();
}
int do_check(object me)
{
    object where=this_object();
    object *obj;
    int i;
    obj=deep_inventory(where);
    if (!sizeof(obj))   return 0;
    for (i=0;i<sizeof(obj);i++){
        if (obj[i]==me) continue;
        if (obj[i]->is_character() && !obj[i]->is_corpse() )
            return 1;
    }
    return 0;
    
}
 
int valid_leave(object me, string dir)
{
    object where;
    
    where=environment(me);
    if (dir == "east"){
        if( where->query("xuanbing"))
            return notify_fail("�㻹û��(xia)���أ��������ܡ�\n");
     }
    return ::valid_leave(me, dir);
}
void init()
{
    object ob=this_player();
    if(userp(ob) && (int)do_check(ob)){
        message_vision("$Nһ���������Ѿ������ˣ�ֻ�����˳�ȥ��\n",ob);
        ob->move(__DIR__"changl13");
        return;
    }
    add_action("do_climb", "climb");
    add_action("do_quit", "quit");
    add_action("do_xia", "xia");
}
int do_quit()
{
     set("xuanbing",0);
     return 0;
}
int do_climb(object me)
{      
        me=this_player();
    if(!me->query_skill("bahuang-gong", 1)||(int)me->query_skill("bahuang-gong", 1) < 10)
       {
        write("��İ˻�����Ψ�Ҷ�����Ϊ���������������溮��\n");                   
        message_vision("$N�Ѿ�������������,��������òҲҵģ��Ͻ�����������\n",me);
        return 1; 
      } 
    message_vision("$N�Ѿ�������������,���ڴ������������ˡ�\n",me);
    set("xuanbing",1);
    return 1;   
}
int do_xia(object me)
{
    object where;
    me=this_player();
    where=environment(me);  
    if (!where->query("xuanbing"))
     return notify_fail("����û�����������µ���ȥѽ����\n");
    set("xuanbing",0);
    message_vision("$N���깦��������������µ�����\n",me);
    return 1;
}
