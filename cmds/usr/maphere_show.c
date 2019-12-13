// ��ʱ��ͼ maphere.c
// Modify by zjpwxh@sjpl 2004.4.24
// Modify by zjpwxh@sjpl 2004.6.2
// �Ľ��������㷨���Թ�ȱ�������ݹ�
// ��������Ӱ���ٶȣ��ݹ���õ��£��������Խ��д������ʹ����Ӧ�ü�����Ѫ

#include <ansi.h>
#include <liebiao.h>

#define MaxX 13
#define MaxY 21

inherit F_CLEAN_UP;
inherit F_COLOR;

static int X,Y;
static mixed m;
static string *rfile;
static mapping *data;
int draw_room(int,int,object);
void set_room(int,int,object);
void set_x_y(int,int,int);

int main(object me, string arg)
{
       object where, *team_objs;
       int i, j, l, n, p, mx, my, my_line;
       int lineu, lined, linef, bit, max_line, flag;
       string *map_line, new_map;
       string tmp, map, team_name, tmp_str;
	   
	   X=MaxX;
	   Y=MaxY;
	   tmp = "";
	   flag = 0;

	   if ( me->query("xieyi/zmud") ) return 0;
	   if ( !me->query("env/myhp_show") ) return 0;

	   where=environment(me);
	   if(!objectp(where)) return notify_fail("����ʺų������⣬�޷�������ʾ��ͼ���뾡����ϵ��ʦ����\n");

	   if ( arg && arg == "-virtual" )
	   {
		   if ( !sscanf(base_name(where), "/adm/daemons/vrm_server%*s") )
			   return notify_fail("ֻ���ڸ�������ܲ鿴������ͼ��\n");
		   if ( file_size("/adm/daemons/vrm_server.map") <= 0 ) 
			   return notify_fail("û�п��õĸ�����ͼ�ļ���\n");
		   if ( stringp(map = read_file("/adm/daemons/vrm_server.map")) ) 
		   {
			   if ( strlen(map) > 8000 )
				   return notify_fail("������ͼ�ļ�̫���ˣ��޷�������ʾ��\n");
			   if ( !sscanf(map, "%*s\n%*s") ) 
				   return notify_fail("������ͼ�ļ���Ч���޷�������ʾ��\n");

			   map_line = explode(map, "\n");
			   max_line = sizeof(map_line);
			   if ( sscanf(base_name(where), "/adm/daemons/vrm_server/new/%*s") )
			   {
				   team_name = "new";
				   team_objs = children(USER_OB);
			   }
			   else
			   {
					team_name = me->query_temp("xyzx_team/name");
					team_objs = TEAMD->get_team_member(me);
			   }
			   for ( i=0; i<sizeof(team_objs); i++ )
			   {
				   if ( !objectp(team_objs[i]) ) continue;
				   if ( !playerp(team_objs[i]) ) continue;
				   where=environment(team_objs[i]);
				   if ( !where ) continue;
				   if ( !virtualp(where) ) continue;
				   if ( sscanf(base_name(where), "/adm/daemons/vrm_server/"+team_name+"/%d/%d", mx, my) == 2 )
				   {
						my_line = max_line - my * 2 - 2;
						tmp_str = map_line[my_line];
						bit = 6 + ((mx+1)*2-1) * 2 - 2;
						tmp_str = tmp_str[0..bit] + "��" + tmp_str[bit+3..];
						map_line[my_line] = tmp_str;
						flag++;
					}
					if ( base_name(where)==("/adm/daemons/vrm_server/"+team_name+"/entry") 
						|| base_name(where)==("/adm/daemons/vrm_server/"+team_name+"/exit") )
						flag++;
			   }
			   where=environment(me);
			   if ( sscanf(base_name(where), "/adm/daemons/vrm_server/"+team_name+"/%d/%d", mx, my) == 2 )
			   {
					my_line = max_line - my * 2 - 2;
					tmp_str = map_line[my_line];
					bit = 6 + ((mx+1)*2-1) * 2 - 2;
					tmp_str = tmp_str[0..bit] + "��" + tmp_str[bit+3..];
					map_line[my_line] = tmp_str;
			   }
			   new_map = implode(map_line, "\n");
			   tmp_str = "\nx����=[";
			   for ( i=0; i<max_line/2; i++)
			   {
				   if ( i == max_line/2-1 )
					   tmp_str += sprintf("%2d", i);
				   else
					   tmp_str += sprintf("%2d��", i);
			   }
			   tmp_str += "]\n";
			   new_map += tmp_str;
			   write(MAP(new_map));
			   write(HIY"Ŀǰ��������к�����ͬһ���һ���� "HIG+flag+HIY" λ��ҡ�\n"NOR);
			   return 1;
		   }
		   return notify_fail("��ȡ������ͼ�ļ�ʧ�ܡ�\n");
	   }

       m=allocate(2*X+1);
       data=allocate((2*X+1)*(2*Y+1));
       rfile=({});
       for(i=0;i<2*X+1;i++)
       {
              m[i]=allocate(2*Y+1);
              for(j=0;j<2*Y+1;j++)
                     m[i][j]=" ";
       }

       draw_room((2*X+1)/2,(2*Y+1)/2,where);

       for(l=0,linef=1;l<2*Y+1;l++)
       {
              for(n=0;n<2*X+1;n++)
              {
                     if( m[n][l]!=" ")
                            p++;
              }
              if(!p && linef)
              {
                     lineu++;
                     linef=1;
              }
              else        linef=0;
              p=0;
       }
       for(l=2*Y,linef=1;l>=0;l--)
       {
              for(n=0;n<2*X+1;n++)
              {
                     if( m[n][l]!=" ")
                            p++;
              }
              if(!p && linef)
              {
                     lined++;
                     linef=1;
              }
              else        linef=0;
              p=0;
       }

       for(i=lineu;i<2*Y+1-lined;i++)
       {
              for(j=0;j<2*X+1;j++)
              {
                     if( m[j][i]==" " && i%2 && j%2 )
                            tmp+="        ";
                     else
                     {
                            //�������Ϊ�գ����Ҵ�ʱjΪż���У�������ո�
                            if( m[j][i]==" " && !(j%2) )
                                   tmp+="  ";
                            else
                            {
                                   if( m[j][i]==" " )
                                          tmp+="        ";

                                   else
                                          tmp+=m[j][i];
                            }
                     }
              }
			  if ( i < 2*Y-lined ) tmp+="\n";
       }

	   write(MAP(clean_color(tmp)));
	   return 1;
}

object find_room(string path)
{
       object ob;
       if( objectp(ob=find_object(path)) || objectp(ob=load_object(path)) )
              return ob;
       return 0;
}

//���������I�J�K�L
int draw_path(int x,int y,string direc)
{
       string str;
       int xx=0,yy=0;
       switch(direc)
       {
              case "south":
              case "north":              str="   ��   ";break;
              case "southdown":          str="   ��   ";break;
              case "northup":            str="   ��   ";break;
              case "southup":            str="   ��   ";break;
              case "northdown":          str="   ��   ";break;
              case "east":
              case "west":               str="��";break;
			  case "eastdown":
              case "eastup":             str="��";break;
              case "westdown":
              case "westup":             str="��";break;           
              case "southeast":
              case "northwest":          str="��";break;
              case "southwest":
              case "northeast":          str="��";break;
			  case "up":
			  case "down":               str="   ��   ";break;
              default:
                     return 0;
       }
       if(sscanf(direc,"%*ssouth%*s"))
              yy++;
       if(sscanf(direc,"%*snorth%*s"))
              yy--;
       if(sscanf(direc,"%*seast%*s"))
              xx++;
       if(sscanf(direc,"%*swest%*s"))
              xx--;
	   /*if(sscanf(direc,"%*sup%*s"))
              yy--;
	   if(sscanf(direc,"%*sdown%*s"))
              yy++;*/
       if( x+xx<=0 || y+yy<=0 || x+xx>=2*X || y+yy>=2*Y )
              return 0;
       m[x+xx][y+yy]=HIW+str+NOR;
       return 1;
}

// ���ù�ȱ���Ѱ·�㷨,ʹ��ͼ����ʾ���Ӻ���
int draw_room(int x,int y,object room)
{
       int i,xx,yy;
       int front,rear;
       string *dirs;
       object froom,nroom;
       mapping dir,x_y;
       object *queue;
       front=0;rear=0;

       queue=allocate( (2*X+1)*(2*Y+1) );
       reset_eval_cost();
       if( x<0 || y<0 || !objectp(room) || x>2*X || y>2*Y )
              return 0;

       rfile=rfile + ({ base_name(room) });
       queue[rear]=room;
       set_room(x,y,room);
       set_x_y(x,y,rear);
       rear++;

       while( front < rear )
       {
              reset_eval_cost();
              froom=queue[front];
              x_y=data[front];
              front++;
              dir=froom->query("exits");
              if( !mapp(dir) || sizeof(dir)<1 )
                     return 0;
              dirs=keys(dir);
                     for(i=0;i<sizeof(dirs);i++)
              {
                              nroom=find_room(dir[dirs[i]]);
                              if(!objectp(nroom) || member_array(base_name(nroom),rfile)!=-1)
                                     continue;
                              xx=0;yy=0;
                     if( sscanf(dirs[i],"%*ssouth%*s"))
                            yy+=2;
                     if( sscanf(dirs[i],"%*snorth%*s"))
                            yy-=2;
                     if( sscanf(dirs[i],"%*seast%*s"))
                            xx+=2;
                     if( sscanf(dirs[i],"%*swest%*s"))
                            xx-=2;
					 /*if( sscanf(dirs[i],"%*sup%*s"))
                            yy-=2;
					 if( sscanf(dirs[i],"%*sdown%*s"))
                            yy+=2;*/
                     if( x_y["xst"]+xx<0 || x_y["yst"]+yy<0 || x_y["xst"]+xx>2*X || x_y["yst"]+yy>2*Y )
                            continue;
                     if( m[x_y["xst"]+xx][x_y["yst"]+yy]!=" ")
                            continue;
                     if( !draw_path(x_y["xst"],x_y["yst"],dirs[i]) || (xx==0&&yy==0))
                            continue;
                     rfile=rfile + ({ base_name(nroom) });
                     queue[rear]=nroom;
                     set_room(x_y["xst"]+xx,x_y["yst"]+yy,nroom);
                     set_x_y(x_y["xst"]+xx,x_y["yst"]+yy,rear);
                     rear++;
              }
       }
}

void set_room(int x,int y,object room)
{
       int i,d,xx,yy,flag;
       string name;
       mapping dir;
       string *dirs;

       // ��ȡ����ɫ�ķ���short����
       name=clean_color(room->query("short"));
       dir=room->query("exits");
    
	if( !mapp(dir) || sizeof(dir)<1 ) 
	{
		flag=1;
	}
	else
	{
       dirs=keys(dir);
       for(i=0;i<sizeof(dirs);i++)
       {
              xx=0;yy=0;
              if( sscanf(dirs[i],"%*ssouth%*s"))
                     yy+=2;
              if( sscanf(dirs[i],"%*snorth%*s"))
                     yy-=2;
              if( sscanf(dirs[i],"%*seast%*s"))
                     xx+=2;
              if( sscanf(dirs[i],"%*swest%*s"))
                     xx-=2;
			  /*if( sscanf(dirs[i],"%*sup%*s"))
                     yy-=2;
              if( sscanf(dirs[i],"%*sdown%*s"))
                     yy+=2;*/
              if( xx==0 && yy==0 )
                     flag=1;
       }
	}

       if((x==(2*X+1)/2)&&(y==(2*Y+1)/2))
              name="��[��]��";
	   else if( flag )
	   {
		   if ( strlen(name) > 6 )  name=name[0..5]+"��";
		   else name+="��";
	   }
	   // ����Ķ����������4����������
       if(strlen(name)>8)  name=name[0..7];

       if(strlen(name)<7) //�Բ���4�����ֵķ��������о��д���
       {
              d=8-strlen(name);
              if( d%2 )
              {
                     name+=" ";
                     d--;
              }
              for(i=0;i<d/2;i++)
                     name=" "+name+" ";
       }
       m[x][y]=name;
}

void set_x_y(int x,int y,int rear)
{
       data[rear]=([
              "xst":x,
              "yst":y,
       ]);
}