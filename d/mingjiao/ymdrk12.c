// Room: ymdrk12.c

inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�ܵ������ֲ�����ָ���㴥����ǽ�ڣ���֪����ʲ��Ӳ�
��ž����һ�����ƹ��������������������۾�����һ�ζ�����
����ԭ�������˻��أ���
LONG
        );
        
        setup();
}

void reset()
{
        ::reset();
        set("exits", ([ /* sizeof() == 4 */
          "south" : __DIR__"ymdrk" + (random(12)+1),
          "north" : __DIR__"ymdrk" + (random(12)+1),
          "west" : __DIR__"ymdrk" + (random(12)+1),
          "east" : __DIR__"ymdrk" + (random(12)+1), 
          "enter" : __DIR__"heiwu"        ]));
}

int valid_leave(object me, string dir)
{
        write("��ʵ��Ū���������....");
        switch(dir) {
                case "north":   write("����....�����������أ�....");    break;
  break;
break;
                case "east":    write("����....����....");      break;
break;
                case "south":   write("�ϱ�....�������ϱߣ�....");      break;
  break;
break;
                case "west":    write("����....��....");        break;
break;
                default:
                        write("������������....");
        }
        write("�����������ɡ�\n");
        return 1;
}

