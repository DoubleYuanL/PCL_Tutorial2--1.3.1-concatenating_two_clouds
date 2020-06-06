#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>

main(int argc, char **argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudA(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudB(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudC(new pcl::PointCloud<pcl::PointXYZ>);
	
	if(pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *cloudA) != 0)
		return -1;
	if(pcl::io::loadPCDFile<pcl::PointXYZ>(argv[2], *cloudB) != 0)
		return -1;
	*cloudC = *cloudA + *cloudB;
	pcl::io::savePCDFile("cloudC.pcd", *cloudC);

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudD(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::Normal>::Ptr cloudE(new pcl::PointCloud<pcl::Normal>);
	pcl::PointCloud<pcl::PointNormal>::Ptr cloudF(new pcl::PointCloud<pcl::PointNormal>);
	cloudD->width = cloudE->width = 3;
	cloudD->height = cloudE->height = 1;
	cloudD->points.resize(cloudD->width*cloudD->height);
	cloudE->points.resize(cloudE->width*cloudE->height);
	for (int i = 0; i < cloudD->points.size(); ++i)
	{
		cloudD->points[i].x = i;
		cloudD->points[i].y = i;
		cloudD->points[i].z = i;
		cloudE->points[i].normal[0] = i;
		cloudE->points[i].normal[1] = i;
		cloudE->points[i].normal[2] = i;
	}
	
	pcl::concatenateFields(*cloudD, *cloudE, *cloudF);
	pcl::io::savePCDFile("cloudF.pcd", *cloudF);

	pcl::visualization::CloudViewer viewer("Cloud3");
	viewer.showCloud(cloudC);
	while(!viewer.wasStopped());
	return 0;
}
