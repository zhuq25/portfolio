1. Title: USPTO Algorithm Challenge, run by NASA-Harvard Tournament Lab and TopCoder
   Problem: Patent Labeling

2. Source Information: 
    -- Creator: Marti Hearst, Christoph Riedl
    -- Marti Hearst: Professor, Computer Science Devision, University of California, Berkeley, Email: hearst@berkeley.edu
    -- Christoph Riedl: Assistant Professor, D'Amore-McKim School of Business and College of Computer and Information Science, Northeastern University,  Email: c.riedl@neu.edu  

3. Past Usage: 
    -- TopCoder: 
	-- USPTO Algorithm Challenge, 
	-- USPTO Algorithm Followup Challenge

4. Dataset Information:
    -- This folder contains 4 groups of USPTO patent images including ground truth information. 
	-- The 4 groups are 'train1', 'train2', 'test', 'evaluation'. 
	-- 'train1', 'test', 'evaluation' contains data in the original "USPTO Algorithm Challenge" for training, testing and final evaluation, respectively.
	-- 'train2' contains additional data which was used in the "USPTO Algorithm Followup Challenge."  
	   Notice that 'train2' includes some cover page images of patent document which is not included in other groups.

    -- In each group, there are two folders contain original images and corresponding ground truth informations. 
	-- The original images are in 'jpeg' format.
	-- There are two types of ground truth: figure label ground truth and part label ground truth.
	-- The ground truth files are text files with '.ans' extension. 

    -- The structure of the ground truth files are described as below:
	-- The first line is one number indicating how many instances exist in corresponding image
	-- The following lines are bounding box coordinates and corresponding label contents, each line corresponds to a figure label or part label, in the form 'N x1 y1 x2 y2 … xN yN x1 y1 content'. 
	-- In each of those lines, the first number N indicates how many bounding box vertices are recorded in current instance. 
	-- The following numbers are x, y coordinates of those vertices.
	-- The final word in each line is the content of figure label or part label. <Notice for figure labels, the word 'Figure', 'Fig' etc. are omitted>
	-- Each number or word is separated by a white space.
	-- For group 'train2', there are only part label ground truth available.
	-- We also release the source code of the top 5 winning solution. See additional archive file.
5. Number of Instances
	306 patent drawing pages
6. Number of Attributes
	Multiple; image files, ground truth files, source code
7. For Each Attribute
	See dataset information above
8. Missing Attribute Values
	No missing values (i.e., all included drawing pages are completely labeled)
9. Class Distribution
	N/A