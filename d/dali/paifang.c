// Room: /d/dali/paifang.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ23��37�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m�Ʒ�[2;37;0m");
	set("long", @LONG
��������һ���Ʒ�֮ǰ���Ʒ��������ĸ���ʴ��֡�[1;33mʥ�����[2;37;0m����
Ϧ�����ڻ��߹�����������ϣ���̻Իͣ�����ĿΪ֮�š�ǰ����һ��
���������д�š�[1;33mʥ�ȹ�[2;37;0m���������֡�
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guangchang",
  "north" : __DIR__"huanggong1",
]));

        set("objects", ([
                __DIR__"npc/shiwei" : 2,
        ]));

	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
    if(dir=="north")
    {
     if( this_player()->query("combat_exp")>256000 )
        {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("shi wei", environment(me))) &&
                   living(present("shi wei", environment(me))))
                    return notify_fail("[1;33m��״�������[2;37;0m��ǰ��ס�㣬����˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�\n"
                        "����Խ������������ֱֳ��С�\n");
        return ::valid_leave(me, dir);
        }
     else
     {
         if(objectp(present("shi wei", environment(me)))&&living(present("wei", environment(me))))
            return notify_fail("[1;33m��״�������[2;37;0m��ס�������������Ϊ����˭����һ��Ѱ�����գ��ѵ���������������ϣ���\n����" + RANK_D->query_rude(me) +"����ҹ�Զ�������Ȼ����Ҳ���������\n");
      }
    }   
return ::valid_leave(me, dir);
}


