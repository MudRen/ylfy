inherit ROOM;			   
      
void create()
{
        set("short", "������");
        set("long",@LONG
�����Ǻ�ľ�µĵڶ����ð׻��õ������ҡ�������ש�̵�.������һ
����(box1).�
LONG );		  
        set("exits", ([	
		 "west"      : __DIR__"qing",
  
]));
       
		          
          set("item_desc", ([
        "box1": "���Ǹ������Ƶĺ���,�����Ա��˴�,�տ���Ҳ ��\n",
        	]) );
 
setup();
         replace_program(ROOM);
}
