//room1.c
inherit ROOM;
void create()
{
  set("short","������");
  set("long",
      "�����ǰ���ɽ���ӵ������ҡ�������ͯ������������\n"
    );
  set("exits",([
      "out" : __DIR__"liangong",
     ]));
 set("objects",([
     __DIR__"npc/tongzi" : 1,
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
        if (userp(obj[i]))
            return 1;
    }
    return 0;
    
}
void init()
{
    object ob=this_player();
    if(userp(ob) && (int)do_check(ob)){
        message_vision("$Nһ���������Ѿ������ˣ�ֻ�����˳�ȥ��\n",ob);
        ob->move(__DIR__"liangong");
    }
}
