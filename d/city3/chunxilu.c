
inherit ROOM;

void create()
{
        set("short", "����·��");
        set("long", @LONG
�����ǳɶ�������ĵش���������·��������Ľֵ���
�ԣ�������������������·�漸�����ճ���Ӱ��·�ϵ�����Ħ
����࣬����Ϊ���Ե����Ʊ����š�һ�ɷ��٣������ľ���
��Զ���Ĺ�����(sign)վ�������¼���������������ʱ�����
�����㡣
LONG);

        set("outdoors", "/d/chengdu");
        set("objects", ([
                __DIR__"npc/weibing" : 2,
            ]));

        set("exits", ([
                "south" : __DIR__"chunxilu1",
                "north" : __DIR__"dongjie1",
            ]));
        set("item_desc", ([ 
            "sign" : "�ɶ��󸮣��Ͻ�����������Ū�ף�\n",
           ]));

        setup();
       
}

int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me))
        {
        if( dir == "south" 
        && ob=present("wei bing", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
                        return notify_fail(ob->name()+"����ȵ����������췴�����������ֱֳ������ܽ�ȥ��\n"); 
                        
                }
        }
        

        return 1;
        }
        else
                return 1;
}

