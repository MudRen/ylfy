//room: chengdedian.c
inherit ROOM;
void create()
{
  set("short","�ɵµ�");
  set("long",
        "�����������̽���ƽ�շ���ʩ��ĵط�, �����޴�, ��ڵ���\n"
        "���λε�����, ���˶˸���һ��, ����һ��Ӣ����������, ����\n"
        "���𽭺��Ķ������ܵ��ͷ����ͤ��!\n" 
     );
  set("exits",([
      "south" : __DIR__"huoting",
      "westdown":__DIR__"up4",
     ]));
  set("objects",([
                               __DIR__"npc/dizi" : 2,
                               __DIR__"npc/yang"    :1,
        ]));
  
 setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        object ob=present("yang lianting", environment(me));
        if (ob && living(ob) ){
            myfam = (mapping)me->query("family");
            if ((!myfam || myfam["family_name"] != "�������") && dir == "south" ) {
                    say("����ͤ��"+me->name()+"�ȵ����㲻�Ǳ��̽��ڣ���������\n");
                    return notify_fail("����ͤ�ȵ��������Ǳ����صأ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
            }
        }
        return ::valid_leave(me, dir);
}


