// jianshi.c

inherit ROOM;
#include <ansi.h>

void create()
{
      set("short", HIC"����"NOR);
      set("long", @LONG
һ�����������ʯ�ң��ܶ��ֽ�������ضѷ��ڵ��ϡ���Χ�Ļ���յ���
��ʯ�ҵƻ�ͨ����������Ĺ������վ��������ϸ��ѡ�Լ����ֵı��С�ǽ�Ƿ�
��һ��ľ�ƵĻ��߼ܣ��������Щ��Ĺ����ƽʱ�����õĻ��ߡ�
LONG
        );

      set("exits", ([
          "south" : __DIR__"gmqs",
      ]));

       set("objects", ([
               "/clone/weapon/changjian" : 2,	
               "/clone/weapon/zhujian" : 2,	
              __DIR__"obj/huju-jia" : 1,
      ]));    
        
      setup();
}

int valid_leave(object ob, string dir)
{
        string* jian = keys(query("objects"));
        object* sword = deep_inventory(ob);
        int i = sizeof(sword), count = 0;
        while (i--)
                if (member_array(base_name(sword[i]), jian) != -1) count++;
        if (count > 1) return notify_fail("��һ��������ô�ལ�����˲�Ҫ������\n");
        return ::valid_leave(ob, dir);
}


