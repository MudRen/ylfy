inherit ROOM;
void create()
{
        set("short", "����¥");
        set("long", @LONG
����¥������佻�Ϫ�ϣ����ȵ�Ϫ�����������·�����������С¥��ֵ�
��ʾ�Ž���С�����ֶ��ؽ��еķ��¥�µ�Ϫˮ����ġ�ż��һ��ֻ��
����Ϫ�Ϸɹ���Ҳ�����ƻ�������ƽ�������ա�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"guanyuge",
		"north" : __DIR__"xiaoxuan" ,
]));
        set("objects", ([
                 __DIR__"npc/dizi" : 2,
                        ]) );
        set("outdoors", "huanhua");
        set("resource/water",1);
        set("coor/x",70);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}
void init()
{
        add_action("do_fillwater", "fillwater");
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "��ˮ",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("��������СϪ����װ������ˮ! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��");
        }
        return 1;
}

